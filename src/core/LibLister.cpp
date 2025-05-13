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
    std::string content;

    if (!std::filesystem::exists(this->_libDirectory))
        throw rayTracer::PathFindingException("Can't find path: '" + this->_libDirectory + "'");
    if (!std::filesystem::is_directory(this->_libDirectory))
        throw rayTracer::PathFindingException("'" + this->_libDirectory + "' is not a directory");
    for (const auto &it : std::filesystem::directory_iterator(this->_libDirectory)) {
        content = it.path().filename().c_str();
        if (!(content[0] == '.' || content.size() < 4 || content.substr(content.size() - 3) != ".so"))
            this->_libs.push_back(content);
    }
}

void rayTracer::LibLister::display() const
{
    std::cout << "Plugins:" << std::endl;
    for (size_t i = 0; i < this->_libs.size(); i++)
        std::cout << this->_libs[i] << std::endl;
}

const std::vector<std::string> &rayTracer::LibLister::getLibs() const
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

const std::string &rayTracer::LibLister::getLibDirectory() const
{
    return this->_libDirectory;
}