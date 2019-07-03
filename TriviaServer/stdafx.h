#pragma once

// Built in dependencies
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <future>
#include <mutex>
#include <WinSock2.h>
#include <Windows.h>


// External libraries
#include "json.hpp"
#include "sqlite3.h"

#pragma comment(lib, "ws2_32.lib")

using json = nlohmann::json;
