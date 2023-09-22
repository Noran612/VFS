#ifndef VFS_H
#define VFS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class File {
public:
    File(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
};

class Directory {
public:
    Directory(const std::string& name) : name(name) {}
    std::string getName() const { return name; }
    void addFile(const File& file);
    void listFiles() const;
    std::vector<File>& getFiles() const { return files; }
private:
    std::string name;
    std::vector<File> files;
};

class VFS {
public:
    void createDirectory(const std::string& name);
    Directory* getDirectory(const std::string& name);
    void listDirectories() const;
    void deleteFile(const std::string& directoryName, const std::string& fileName);
    void copyFile(const std::string& sourceDir, const std::string& sourceFile, const std::string& destDir);
    void searchFile(const std::string& fileName) const;
    void encryptFile(const std::string& directoryName, const std::string& fileName);
    void compressFile(const std::string& directoryName, const std::string& fileName);
private:
    std::vector<Directory> directories;
};

#endif
