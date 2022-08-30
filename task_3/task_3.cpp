#include "task_3.hpp"

Statistics::Statistics(std::string path_init): path(path_init) {}

int Statistics::get_files_processed()
{
    return files_processed;
}

int Statistics::get_code_lines()
{
    return code_lines;
}

int Statistics::get_blank_lines()
{
    return blank_lines;
}

int Statistics::get_comment_lines()
{
    return comment_lines;
}

time_t Statistics::get_exec_time()
{
    return exec_time;
}

/* Thread function */
void count_lines(std::string entry, Statistics* obj)
{
    lock.lock();

    int code_lines = 0;
    int comment_lines = 0;
    int blank_lines = 0;

    std::string buffer;
    std::ifstream file(entry);

    bool comment_flag = false;

    while (std::getline(file, buffer))
    {
        if (!comment_flag)
        {
            if (buffer == "")
                blank_lines++;
            else if (buffer.find("//") != std::string::npos)
                comment_lines++;
            else if (buffer.find("/*") != std::string::npos)
            {
                if (buffer.find("*/") != std::string::npos)
                    comment_flag = true;
                comment_lines++;
            }
            else
                code_lines++;
        }
        else
            if (buffer.find("*/") != std::string::npos)
            {
                comment_lines++;
                comment_flag = false;
            }
    }
    
    obj->code_lines += code_lines;
    obj->comment_lines += comment_lines;
    obj->blank_lines += blank_lines;
    
    lock.unlock();
}

/* Saves results of the worker function to file results.txt */
void Statistics::save_results()
{
    std::ofstream file("results.txt");

    if (file.is_open())
    {
        file << "Processed files: " << files_processed << std::endl;
        file << "Blank lines: " << blank_lines << std::endl;
        file << "Comment lines: " << comment_lines << std::endl;
        file << "Code lines: " << code_lines << std::endl;
        file << "Execution time: " << exec_time << " micro seconds." << std::endl;

        file.close();
    }
    else
    {
        std::cout << "Problem with opening file." << std::endl;
    }

    std::cout << "Processed files: " << files_processed << std::endl;
    std::cout << "Blank lines: " << blank_lines << std::endl;
    std::cout << "Comment lines: " << comment_lines << std::endl;
    std::cout << "Code lines: " << code_lines << std::endl;
    std::cout << "Execution time: " << exec_time << " micro seconds." << std::endl;
}

/* Worker function */
void Statistics::work()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    int files_count = 0;
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        std::string extension = entry.path().extension();
        if (valid_extensions.find(extension) != valid_extensions.end())
            files_count++;
    }

    std::thread* threads = new std::thread[files_count];

    int i = 0;
    for (const auto & entry : std::filesystem::directory_iterator(path))
    {
        std::string extension = entry.path().extension();
        if (valid_extensions.find(extension) != valid_extensions.end())
        {
            threads[i] = std::thread(count_lines, entry.path(), this);
            i++;
            files_processed++;
        }
    }

    for (i = 0; i < files_count; i++)
        threads[i].join();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    exec_time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    save_results();
}