#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <fstream>
#include <ctime>

void saveDir(int i) {
    // Remplacez les placeholders ci-dessous par vos propres informations

    std::string sshKeyPath = "<chemin_vers_la_clé_ssh>";

    std::string serverUsername = "<nom_utilisateur_server>";

    std::string serverIP = "<adresse_IP_serveur>";

    std::string scpCommand = "scp -i " + sshKeyPath + " -p -r " + serverUsername + "@" + serverIP + ":~/server ~/backup/saves";
    system(scpCommand.c_str());
    system("find ~/backup/saves/server -type f -exec chmod 644 {} \\;");
    std::string folder = "~/backup/server_" + std::to_string(i);
    system(("mv ~/backup/saves/server " + folder).c_str());
    std::cout << "Transfert succeed" << std::endl;
}

void generateLogs() {
    std::string filename = "~/backup/backup.log";
    std::fstream file;
    file.open(filename, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << ".\n";
        return;
    } else {
        std::time_t now = std::time(nullptr);
        std::tm* now_tm = std::localtime(&now);
        char time_buf[sizeof("YYYY-MM-DD HH:MM:SS")];
        std::strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", now_tm);
        file << time_buf << " [===================]     save success" << std::endl;
        file.close();
    }
}

int main() {
    int i = 1;
    for (int j = 0; j < 5; j++) {
        saveDir(i);
        std::cout << "Transfert succeed" << std::endl;
        generateLogs();
        std::cout << "Logs generated" << std::endl;
        sleep(1);
        i++;
    }
    std::cout << "end" << std::endl;
    return 0;
}
