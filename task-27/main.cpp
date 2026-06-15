// Task 27: Display server status from a predefined list.
// Show online servers, offline servers, and servers with high resource usage
// (CPU load >= 70% or RAM usage >= available RAM).

#include <iostream>
using namespace std;

struct Server {
    string hostname;
    string ipAddress;
    int cpuLoad;
    int ramUsage;
    bool isOnline;
};

Server servers[9] = {
    { "server_1", "192.168.1.101", 45,  8598, true  },
    { "server_2", "192.168.1.102", 85,  1645, true  },
    { "server_3", "192.168.1.103", 10,  4491, false },
    { "server_4", "192.168.1.104", 75,  1253, false },
    { "server_5", "192.168.1.105", 23,  3762, true  },
    { "server_6", "192.168.1.106", 42,  9651, true  },
    { "server_7", "192.168.1.107", 76,  7325, true  },
    { "server_8", "192.168.1.108", 95, 12681, true  },
    { "server_9", "192.168.1.109", 41,  3661, false },
};

void showData(Server s) {
    cout << "HOSTNAME: " << s.hostname
         << " | IP: "   << s.ipAddress
         << " | CPU: "  << s.cpuLoad  << "%"
         << " | RAM: "  << s.ramUsage << " MB" << endl;
}

int main() {
    int availableRam = 16384;

    cout << "=== Online Servers ===\n";
    for (int i = 0; i < 9; i++)
        if (servers[i].isOnline) showData(servers[i]);

    cout << "\n=== Offline Servers ===\n";
    for (int i = 0; i < 9; i++)
        if (!servers[i].isOnline) showData(servers[i]);

    cout << "\n=== High Resource Usage ===\n";
    for (int i = 0; i < 9; i++)
        if (servers[i].cpuLoad >= 70 || servers[i].ramUsage >= availableRam)
            showData(servers[i]);

    cout << endl;
    return 0;
}
