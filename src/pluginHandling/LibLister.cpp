/*
** EPITECH PROJECT, 2025
** rayTracer
** File description:
** LibLister
*/

#include "pluginHandling/LibLister.hpp"

rayTracer::LibLister::LibLister() :
_libDirectory(PLUGINS_DIR)
{
    DIR *dir = opendir(PLUGINS_DIR);
    struct dirent *dirent;
    std::string tmp;

    if (!dir)
        throw PathFindingException("Can't find 'lib' directory");
    dirent = readdir(dir);
    while (dirent) {
        tmp = dirent->d_name;
        if (!(tmp[0] == '.' || tmp.size() < 11 || tmp.substr(tmp.size() - 3) != ".so"))
            this->saveLib(dirent->d_name);
        dirent = readdir(dir);
    }
    closedir(dir);
}

void rayTracer::LibLister::saveLib(std::string lib)
{
    size_t sep = lib.find("_");
    std::string type;

    if (sep != lib.npos) {
        type = lib.substr(0, sep);
        if (type == "primitive")
            this->_primitive.push_back(lib);
        else if (type == "light")
            this->_light.push_back(lib);
        else
            this->_other.push_back(lib);
    } else
        this->_other.push_back(lib);
}

void rayTracer::LibLister::display() const
{
    std::cout << "[PLUGINS]" << std::endl;
    std::cout << "primitive:" << std::endl;
    for (size_t i = 0; i < this->_primitive.size(); i++)
        std::cout << "--" << this->_primitive[i] << std::endl;
    std::cout << "light:" << std::endl;
    for (size_t i = 0; i < this->_light.size(); i++)
        std::cout << "--" << this->_light[i] << std::endl;
    std::cout << "other:" << std::endl;
    for (size_t i = 0; i < this->_other.size(); i++)
        std::cout << "--" << this->_other[i] << std::endl;
}

const std::vector<std::string> &rayTracer::LibLister::getLibs()
{
    return this->_other;
}


int rayTracer::LibLister::getIndexLib(const std::string &path) const
{
    int index = 0;

    for (std::string libName : this->_other) {
        if (libName == path || this->_libDirectory + libName == path) {
            return index;
        }
        index++;
    }
    return -1;
}

const std::vector<std::string> &rayTracer::LibLister::getPrimitive() const
{
    return this->_primitive;
}

const std::vector<std::string> &rayTracer::LibLister::getLight() const
{
    return this->_light;
}

const std::vector<std::string> &rayTracer::LibLister::getOther() const
{
    return this->_other;
}
