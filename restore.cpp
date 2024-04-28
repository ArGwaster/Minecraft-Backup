#include <iostream>
#include <cstdlib>

void push() {
    // Remplacez les placeholders ci-dessous par vos propres informations

    std::string sshKeyPath = "<chemin_vers_la_clé_ssh>";

    std::string serverUsername = "<nom_utilisateur_server>";

    std::string serverIP = "<adresse_IP_serveur>";

    std::string scpCommand = "scp -i " + sshKeyPath + " -r ~/backup/saves/server " + serverUsername + "@" + serverIP + ":/home/" + serverUsername + "/";
    system(scpCommand.c_str());
    std::cout << "Push success" << std::endl;
}

int main() {
    push();
    return 0;
}
