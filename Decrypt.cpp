#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

map<char, char> encryptionMapping;

void initializeEncryptionMapping() {
    srand(time(nullptr));
    string decryptedChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,.!? ";
    string encryptedChars = decryptedChars;

    // Shuffle the encryptedChars
    std::shuffle(encryptedChars.begin(), encryptedChars.end(), std::default_random_engine(time(nullptr)));

    for (size_t i = 0; i < decryptedChars.size(); i++) {
        encryptionMapping[decryptedChars[i]] = encryptedChars[i];
    }
}

string customDecrypt(string text) {
    for (char& c : text) {
        for (const auto& entry : encryptionMapping) {
            if (c == entry.second) {
                c = entry.first;
                break;
            }
        }
    }
    return text;
}

void printAsciiArt() {
    const std::string colors[] = {
        "\033[91m", "\033[93m", "\033[92m", "\033[94m", "\033[95m", "\033[96m"
    };
    int numColors = sizeof(colors) / sizeof(colors[0]);
    int colorIndex = 0;

    const std::string asciiArt =
        "      :::::::::      :::     :::::::::  :::    ::: :::::::::  :::   ::: ::::::::: ::::::::::: ::::::::  ::::::::: \n"
        "     :+:    :+:   :+: :+:   :+:    :+: :+:   :+:  :+:    :+: :+:   :+: :+:    :+:    :+:    :+:    :+: :+:    :+: \n"
        "    +:+    +:+  +:+   +:+  +:+    +:+ +:+  +:+   +:+    :+:  +:+ +:+  +:+    +:+    +:+    +:+    +:+ +:+    :+:  \n"
        "   +#+    +:+ +#++:++#++: +#++:++#:  +#++:++    +#++:++#:    +#++:   +#++:++#+     +#+    +#+    +:+ +#++:++#:    \n"
        "  +#+    +#+ +#+     +#+ +#+    +#+ +#+  +#+   +#+    +#+    +#+    +#+           +#+    +#+    +#+ +#+    +#+    \n"
        " #+#    #+# #+#     #+# #+#    #+# #+#   #+#  #+#    #+#    #+#    #+#           #+#    #+#    #+# #+#    #+#     \n"
        "#########  ###     ### ###    ### ###    ### ###    ###    ###    ###           ###     ########  ###    ###    \n";

    for (char c : asciiArt) {
        if (c == '\n') {
            colorIndex = (colorIndex + 1) % numColors;
            std::cout << "\033[0m"; // Reset color
            std::cout << colors[colorIndex];
        }
        std::cout << c;
    }
    std::cout << "\033[0m" << std::endl; // Reset color at the end
}

int main() {
    string plaintext;
    string encryptedText;
    string decryptedText;

    printAsciiArt();
    initializeEncryptionMapping();

    cout << "Enter a string to decrypt: ";
    getline(cin, plaintext);

    decryptedText = customDecrypt(plaintext);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
