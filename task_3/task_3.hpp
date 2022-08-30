#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <string>
#include <unordered_set>
#include <mutex>

std::unordered_set<std::string> valid_extensions = { ".c", ".h", ".cpp", ".hpp" };
std::mutex lock;

class Statistics
{
private:
    int files_processed;
    int code_lines;
    int blank_lines;
    int comment_lines;

    std::string path;
    time_t exec_time;

public:
    Statistics(std::string path_init);

    int get_files_processed();
    int get_code_lines();
    int get_blank_lines();
    int get_comment_lines();

    time_t get_exec_time();

    friend void count_lines(std::string entry, Statistics* obj);
    void save_results();
    void work();
};