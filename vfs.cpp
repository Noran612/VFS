#include "vfs.h"

void Directory::addFile(const File& file) {
    files.push_back(file);
}

void Directory::listFiles() const {
    std::cout << "Files in Directory '" << name << "':" << std::endl;
    for (const auto& file : files) {
        std::cout << "- " << file.getName() << std::endl;
    }
}

void VFS::createDirectory(const std::string& name) {
    directories.emplace_back(name);
}

Directory* VFS::getDirectory(const std::string& name) {
    for (auto& directory : directories) {
        if (directory.getName() == name) {
            return &directory;
        }
    }
    return nullptr;
}

void VFS::listDirectories() const {
    std::cout << "Directories in VFS:" << std::endl;
    for (const auto& directory : directories) {
        std::cout << "- " << directory.getName() << std::endl;
    }
}
//this is a comment

int main() {
    VFS vfs;
    vfs.createDirectory("Documents");
    vfs.createDirectory("Photos");

    Directory* documents = vfs.getDirectory("Documents");
    if (documents) {
        documents->addFile(File("Assignment.docx"));
        documents->addFile(File("Report.pdf"));
    }

    Directory* photos = vfs.getDirectory("Photos");
    if (photos) {
        photos->addFile(File("Vacation.jpg"));
        photos->addFile(File("FamilyPic.jpg"));
    }

    vfs.listDirectories();

    if (documents) {
        documents->listFiles();
    }

    if (photos) {
        photos->listFiles();
    }

    return 0;
}
void VFS::deleteFile(const std::string& directoryName, const std::string& fileName) {
    Directory* directory = getDirectory(directoryName);
    if (directory) {
        std::vector<File>& files = directory->getFiles();
        auto it = std::remove_if(files.begin(), files.end(), [&](const File& file) {
            return file.getName() == fileName;
        });
        if (it != files.end()) {
            files.erase(it, files.end());
            std::cout << "File '" << fileName << "' deleted from Directory '" << directoryName << "'." << std::endl;
        } else {
            std::cout << "File '" << fileName << "' not found in Directory '" << directoryName << "'." << std::endl;
        }
    } else {
        std::cout << "Directory '" << directoryName << "' not found." << std::endl;
    }
}

void VFS::copyFile(const std::string& sourceDir, const std::string& sourceFile, const std::string& destDir) {
    Directory* sourceDirectory = getDirectory(sourceDir);
    Directory* destDirectory = getDirectory(destDir);
    if (sourceDirectory && destDirectory) {
        const std::vector<File>& sourceFiles = sourceDirectory->getFiles();
        for (const File& file : sourceFiles) {
            if (file.getName() == sourceFile) {
                destDirectory->addFile(file);
                std::cout << "File '" << sourceFile << "' copied from '" << sourceDir << "' to '" << destDir << "'." << std::endl;
                return;
            }
        }
        std::cout << "File '" << sourceFile << "' not found in Directory '" << sourceDir << "'." << std::endl;
    } else {
        std::cout << "Source or destination directory not found." << std::endl;
    }
}

void VFS::searchFile(const std::string& fileName) const {
    std::cout << "Searching for file '" << fileName << "':" << std::endl;
    for (const Directory& directory : directories) {
        const std::vector<File>& files = directory.getFiles();
        for (const File& file : files) {
            if (file.getName() == fileName) {
                std::cout << "Found in Directory '" << directory.getName() << "'." << std::endl;
            }
        }
    }
    std::cout << "Search complete." << std::endl;
}

void VFS::encryptFile(const std::string& directoryName, const std::string& fileName) {
    Directory* directory = getDirectory(directoryName);
    if (directory) {
        std::vector<File>& files = directory->getFiles();
        for (File& file : files) {
            if (file.getName() == fileName) {
                // Implement encryption logic here (e.g., using a library or algorithm)
                std::cout << "File '" << fileName << "' in Directory '" << directoryName << "' encrypted." << std::endl;
                return;
            }
        }
        std::cout << "File '" << fileName << "' not found in Directory '" << directoryName << "'." << std::endl;
    } else {
        std::cout << "Directory '" << directoryName << "' not found." << std::endl;
    }
}

void VFS::compressFile(const std::string& directoryName, const std::string& fileName) {
    Directory* directory = getDirectory(directoryName);
    if (directory) {
        std::vector<File>& files = directory->getFiles();
        for (File& file : files) {
            if (file.getName() == fileName) {
                // Implement compression logic here (e.g., using a library or algorithm)
                std::cout << "File '" << fileName << "' in Directory '" << directoryName << "' compressed." << std::endl;
                return;
            }
        }
        std::cout << "File '" << fileName << "' not found in Directory '" << directoryName << "'." << std::endl;
    } else {
        std::cout << "Directory '" << directoryName << "' not found." << std::endl;
    }
}