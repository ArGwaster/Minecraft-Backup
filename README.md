# Minecraft-Backup

---

# Scripts

## Récupérer les fichiers de la VM admin

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <fstream>
#include <ctime>

void saveDir(int i) {
        system("scp -i ~/backup/sshkey.pem -p -r minecraft_admin@4.227.191.244:~/server ~/backup/saves");
        system("find /home/otot/backup/saves/server -type f -exec chmod 644 {} \\;");
        std::string folder = "/home/otot/backup/server_";
        folder += std::to_string(i);
        system(("mv /home/otot/backup/saves/server " + folder).c_str());
        std::cout << "Transfert succeed" << std::endl;
        return;
}

void generateLogs() {
        std::string filename = "/home/otot/backup/backup.log";
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
                std::cout << "Tranfert succeed" << std::endl;
                generateLogs();
                std::cout << "Logs generated" << std::endl;
                sleep(1);
                i++;
        }
        std::cout << "end" << std::endl;
        return 0;
}
```

## Transférer les fichiers récupérés à la VM admin

```cpp
#include <iostream>
#include <cstdlib>
#include <cstdio>

void push() {
        system("scp -i /home/otot/backup/sshkey.pem -r ~/backup/saves/server minecraft_admin@4.227.191.244:/home/minecraft_admin/");
        system("logout");
        std::cout << "Push success" << std::endl;
        return;
}

int main() {
        push();
        return 0;
}
```