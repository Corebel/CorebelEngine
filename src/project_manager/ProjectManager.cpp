// File: src/project_manager/ProjectManager.cpp

#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <zlib.h>

class ProjectManager {
public:
    bool createProject(const std::string& path);
    bool loadProject(const std::string& path);
    bool saveProject(const std::string& path);

private:
    rapidjson::Document projectData;
};

bool ProjectManager::createProject(const std::string& path) {
    boost::filesystem::path projectPath(path);

    if (!boost::filesystem::create_directory(projectPath)) {
        std::cerr << "Failed to create project directory: " << path << std::endl;
        return false;
    }

    // Create basic project structure
    boost::filesystem::create_directory(projectPath / "assets");
    boost::filesystem::create_directory(projectPath / "configs");

    std::cout << "Project created at " << path << std::endl;
    return true;
}

bool ProjectManager::loadProject(const std::string& path) {
    std::ifstream configFile(path + "/configs/project.json");
    if (!configFile.is_open()) {
        std::cerr << "Failed to open project file: " << path << std::endl;
        return false;
    }

    std::string configContent((std::istreambuf_iterator<char>(configFile)),
                               std::istreambuf_iterator<char>());

    projectData.Parse(configContent.c_str());
    if (projectData.HasParseError()) {
        std::cerr << "Failed to parse project configuration." << std::endl;
        return false;
    }

    std::cout << "Project loaded successfully from " << path << std::endl;
    return true;
}

bool ProjectManager::saveProject(const std::string& path) {
    std::ofstream configFile(path + "/configs/project.json");
    if (!configFile.is_open()) {
        std::cerr << "Failed to write project file: " << path << std::endl;
        return false;
    }

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    projectData.Accept(writer);

    configFile << buffer.GetString();
    std::cout << "Project saved successfully to " << path << std::endl;
    return true;
}
