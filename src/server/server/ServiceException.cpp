#include "ServiceException.hpp"

namespace server {

    ServiceException::ServiceException (HttpStatus status, string msg) 
        : httpStatus(status),msg(msg) {    
    }

    HttpStatus ServiceException::status () const {
        return httpStatus;
    }

    const char* ServiceException::what () const {
        return msg.c_str();
    }
    
    HttpStatus ServiceException::getHttpStatus() const {
        return httpStatus;
    }
    
    void ServiceException::setHttpStatus(HttpStatus httpStatus) {
        this->httpStatus = httpStatus;
    }
    
    const std::string& ServiceException::getMsg() const {
        return msg;
    }
    
    void ServiceException::setMsg(const std::string& msg) {
        this->msg = msg;
    }
};