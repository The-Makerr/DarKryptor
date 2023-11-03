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

string customEncrypt(string text) {
    for (char& c : text) {
        if (encryptionMapping.find(c) != encryptionMapping.end()) {
            c = encryptionMapping[c];
        }
    }
    return text;
}

void printAsciiArt() {
    cout << "      :::::::::      :::     :::::::::  :::    ::: :::::::::  :::   ::: ::::::::: ::::::::::: ::::::::  ::::::::: \n";
    cout << "     :+:    :+:   :+: :+:   :+:    :+: :+:   :+:  :+:    :+: :+:   :+: :+:    :+:    :+:    :+:    :+: :+:    :+: \n";
    cout << "    +:+    +:+  +:+   +:+  +:+    +:+ +:+  +:+   +:+    :+:  +:+ +:+  +:+    +:+    +:+    +:+    +:+ +:+    :+:  \n";
    cout << "   +#+    +:+ +#++:++#++: +#++:++#:  +#++:++    +#++:++#:    +#++:   +#++:++#+     +#+    +#+    +:+ +#++:++#:    \n";
    cout << "  +#+    +#+ +#+     +#+ +#+    +#+ +#+  +#+   +#+    +#+    +#+    +#+           +#+    +#+    +#+ +#+    +#+    \n";
    cout << " #+#    #+# #+#     #+# #+#    #+# #+#   #+#  #+#    #+#    #+#    #+#           #+#    #+#    #+# #+#    #+#     \n";
    cout << "#########  ###     ### ###    ### ###    ### ###    ###    ###    ###           ###     ########  ###    ###    \n";
    cout << "\n";
}

int main() {
    string plaintext;
    string encryptedText;
    string decryptedText;

    printAsciiArt();
    initializeEncryptionMapping();

    cout << "Enter a string to encrypt: ";
    getline(cin, plaintext);
    encryptedText = customEncrypt(plaintext);
    cout << "Encrypted: " << encryptedText << endl;

    while (true) {

    }
    return 0;
}
