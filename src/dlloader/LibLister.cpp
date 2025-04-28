/*
** EPITECH PROJECT, 2025
** rayTracer
** File description:
** LibLister
*/

#include "LibLister.hpp"

rayTracer::LibLister::LibLister() :
_libDirectory(PLUGINS_DIR)
{
    DIR *dir = opendir(PLUGINS_DIR);
    struct dirent *dirent;
    std::string tmp;

    if (!dir)
        throw PathFindingException("Can't find 'lib directory: " + std::string(PLUGINS_DIR));
    dirent = readdir(dir);
    while (dirent) {
        tmp = dirent->d_name;
        if (!(tmp[0] == '.' || tmp.size() < 4 || tmp.substr(tmp.size() - 3) != ".so"))
            this->_libs.push_back(dirent->d_name);
        dirent = readdir(dir);
    }
    closedir(dir);
}

void rayTracer::LibLister::display() const
{
    std::cout << "Plugins:" << std::endl;
    for (size_t i = 0; i < this->_libs.size(); i++)
        std::cout << this->_libs[i] << std::endl;
}

const std::vector<std::string> &rayTracer::LibLister::getLibs()
{
    return this->_libs;
}


int rayTracer::LibLister::getIndexLib(const std::string &path) const
{
    int index = 0;

    for (std::string libName : this->_libs) {
        if (libName == path || this->_libDirectory + libName == path) {
            return index;
        }
        index++;
    }
    return -1;
}

std::string rayTracer::LibLister::getLibDirectory() const
{
    return this->_libDirectory;
}