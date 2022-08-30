#include "task_3.cpp"

int main()
{
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;

    Statistics* App = new Statistics(path);
    App->work();

    return 0;
}