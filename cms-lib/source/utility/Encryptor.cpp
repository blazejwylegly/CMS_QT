#include "Encryptor.h"

const std::string& Encryptor::encode(std::string& password, std::string& salt){
    QCryptographicHash hash(QCryptographicHash::RealSha3_256);

    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    salt = std::to_string(generator.generate64());

    std::string str = password + salt;
    hash.addData(str.c_str(), str.length());
    password = hash.result().toHex().toStdString();

    return password;
}

const std::string Encryptor::constEncode(const std::string& password, const std::string& salt){
    QCryptographicHash hash(QCryptographicHash::RealSha3_256);
    std::string tmp = password + salt;
    hash.addData(tmp.c_str(), tmp.length());
    return hash.result().toHex().toStdString();
}
