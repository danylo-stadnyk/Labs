#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <exception>
#include <string>



class LabException: public std::exception {
protected:
std::string msg;
public:
explicit LabException(const std::string &m): msg(m) {}
const char* what() const noexcept override { return msg.c_str(); }
};


class FileException: public LabException {
public:
explicit FileException(const std::string &m): LabException("File error: " + m) {}
};


class InputException: public LabException {
public:
explicit InputException(const std::string &m): LabException("Input error: " + m) {}
};


#endif