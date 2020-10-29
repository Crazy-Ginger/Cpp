#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream file;
    file.open("/mnt/d/Photos/toView.txt");
    std::string line;
    std::vector<std::string> photos;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            photos.push_back(line);
        }
    }
    for (unsigned int i = 0; i < photos.size(); i++)
    {
        std::cout << photos[i] << std::endl;
    }
    std::cout << "Size: " << photos.size() << std::endl;
    std::string waste;
    std::cin >> waste;

    return 0;
}
