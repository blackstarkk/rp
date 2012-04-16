#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

/**
 * \def RAISE_EXCEPTION(msg)
 *  It raises an exception with a detailed explanation in "msg"
 *
 * \param msg: The message that will be associated to the exeception raised
 */
#define RAISE_EXCEPTION(msg) throw RpException(__FILE__,  __LINE__, __FUNCTION__, msg)

/*! \class RpException
 *
 *  RpException is there to have a simple exception report ; easier to corret bugs
 */
class RpException : public std::exception
{
    public:
        
        /*!
         *  \brief Build an RpException
         *   
         *  \param filename: The name of the file where the exception has been raised
         *  \param line: The line where the exception has been raised
         *  \param funct: The function name where the exception has been raised
         *  \param msg: It is a message that describes the reason of the exception
         */
        explicit RpException(const char *filename, unsigned int line, const char* funct, const char* msg);

        ~RpException(void) throw();

        /*!
         *  \brief Obtain the reason the exception
         *   
         *  \return A message describing the exception
         */
        const char* what(void) const throw();

    private:

        std::string m_filename, /*!< the name of the file where the exception has been raised */
            m_msg, /*!< the message that describes the reason of the exception */
            m_function_name, /*!< the function name where the exception has been raised */
            m_report; /*!< the name of the file where the exception has been raised */

        unsigned int m_line; /*!< the line where the exception has been raised */
};

#endif
