#pragma once
#include <iostream>

#include <QRandomGenerator>
#include <QDebug>
#include <QCryptographicHash>

#include <stdio.h>
#include <string.h>
#include <algorithm>

class Encryptor
{
public:
    //account creation - initializing pwd (hash) and salt with new values,
    //returns hash for comparsion pourposes
    static const std::string& encode(std::string& password, std::string& salt);
    //login - encryption using given pwd and salt
    static const std::string constEncode(const std::string& password, const std::string& salt);
};

