#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <pthread.h>
#include "src/lexer.h"

const int NUM_THREADS = 16;

struct Block
{
    int start;
    int end;
    vector<string> inputFiles;
};

void *task(void *arg)
{
    Block *block = (Block *)arg;
    Lexer lexer;
    for (int i = block->start; i < block->end; i++)
    {
        std::ifstream input(block->inputFiles[i]);
        std::string inputString((std::istreambuf_iterator<char>(input)),
                                std::istreambuf_iterator<char>());
        inputString = lexer.lex(inputString);

        std::ofstream output_file(block->inputFiles[i] + ".html");

        output_file << "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><pre>"
                    << inputString
                    << "</pre>";

        output_file.close();
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <input files>" << std::endl;
        return 1;
    }

    std::vector<std::string> inputFiles;

    for (int i = 1; i < argc; i++)
    {
        inputFiles.push_back(argv[i]);
    }

    auto start = std::chrono::high_resolution_clock::now();
    Lexer lexer;

    for (auto inputFile : inputFiles)
    {
        std::ifstream input(inputFile);
        std::string inputString((std::istreambuf_iterator<char>(input)),
                                std::istreambuf_iterator<char>());
        inputString = lexer.lex(inputString);

        std::ofstream output_file(inputFile + ".html");

        output_file << "<head> <link rel='stylesheet' href='styles.css'> <title>problemSituation</title> </head><pre>"
                    << inputString
                    << "</pre>";

        output_file.close();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto durationSingle = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << durationSingle.count() << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    pthread_t threads[NUM_THREADS];
    Block blocks[NUM_THREADS];
    int blockSize = inputFiles.size() / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++)
    {
        blocks[i].start = i * blockSize;
        blocks[i].end = (i + 1) * blockSize;
        if (i == NUM_THREADS - 1)
        {
            blocks[i].end = inputFiles.size();
        }
        blocks[i].inputFiles = inputFiles;
        pthread_create(&threads[i], NULL, task, (void *)&blocks[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    end = std::chrono::high_resolution_clock::now();

    auto durationMulti = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Time taken: " << durationMulti.count() << "ms" << std::endl;

    std::cout << "Speedup: " << (float)durationSingle.count() / durationMulti.count() << "x" << std::endl;

    return 0;
}
