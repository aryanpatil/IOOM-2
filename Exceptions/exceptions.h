/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/



#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include<iostream>
#include<exception>
#include<cstring>

using namespace std;

// Exception for File I/O

class io_exception : std::exception {
    private:
    std::string filename;

    public:
    // Returns Error Message
    const char * what() const throw() override {  
        return "ERROR: unable to open file\n";
    }

    // Constructor
    io_exception(std::string fname) {
        this->filename = fname;
    }

    virtual ~io_exception() throw() { return; }
};



// Exception for File Not Found

class file_not_found : std::exception {
    private: 
    std::string filename;

    public:
    // Returns Error Message
    const char * what() const throw() override {
        std::string msg = "ERROR: unable to find file at path: " + filename + "\n";
        char * m = new char[msg.size() + 1];
        strcpy(m, msg.c_str());
        return m;
    }

    // Constructor
    file_not_found(std::string fname) {
        this->filename = fname;
    }

    virtual ~file_not_found() throw() { return; }

};



// Exception for Access Denied

class access_denied_exception : std::exception {
    private:
    std::string path;

    public:
    //  Returns Error Message
    const char * what() const throw() override {
        std::string msg =  "ERROR: access denied to " + this->path + "\n";
        char * m = new char[msg.size() + 1];
        strcpy(m, msg.c_str());
        return m;
    }

    // Constructor
    access_denied_exception(std::string path) { this->path = path; }

    virtual ~access_denied_exception() throw() { return; }
};  

#endif
