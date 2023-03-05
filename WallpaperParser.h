#pragma once
#include <string>
#include <map>
#include "Wallpaper.h"
#include <iostream>
#include <filesystem>
#include <regex>


class WallpaperParser
{
private:
    std::string _pathToFolder;

public:
    WallpaperParser(std::string pathToFolder);

    std::vector<std::tuple<type, std::string>> ParseFromFolder();
};
