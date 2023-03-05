#include "WallpaperParser.h"
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

WallpaperParser::WallpaperParser(std::string pathToFolder)
{
    this->_pathToFolder = pathToFolder;
}

std::vector<std::tuple<type, std::string>> WallpaperParser::ParseFromFolder()
{
    std::vector<std::tuple<type, std::string>> wallpapers;
    for (auto i = directory_iterator(_pathToFolder); i != directory_iterator(); i++)
    {
        
        if (!is_directory(i->path()))
        {
            std::regex photo(".+[.]jpg|.+[.]png");
            std::regex video(".+[.]mp4");
            if (std::regex_match(i->path().filename().string(), photo)) {
                std::tuple<type, std::string> temp = *new std::tuple<type, std::string>(type::photo, i->path().filename().string());
                wallpapers.push_back(temp);
            }
            if (std::regex_match(i->path().filename().string(), video)) {
                std::tuple<type, std::string> temp = *new std::tuple<type, std::string>(type::video, i->path().filename().string());
                wallpapers.push_back(temp);
            }
            else
                continue;
        }
        else
            continue;
    }
    return wallpapers;
}
