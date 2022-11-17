#ifndef TGBOT_HTTPPARAMETER_H
#define TGBOT_HTTPPARAMETER_H

#include "tgbot/export.h"

#include <boost/lexical_cast.hpp>

#include <string>
#include <vector>
#include <functional>

namespace TgBot
{

    /**
     * @brief This class represents argument in POST http requests.
     *
     * @ingroup net
     */
    class TGBOT_API HttpReqArg
    {

    public:
        template <typename T>
        HttpReqArg(std::string nameP, const T &valueP, bool isFileP = false, std::string mimeTypeParameter = "text/plain", std::string fileNameParameter = "") : name(std::move(nameP)), value(boost::lexical_cast<std::string>(valueP)), isFile(isFileP), mimeType(std::move(mimeTypeParameter)), fileName(std::move(fileNameParameter))
        {
        }

        /**
         * @brief Name of an argument.
         */
        std::string name;

        /**
         * @brief Value of an argument.
         */
        std::string value;

        /**
         * @brief Should be true if an argument value hold some file contents
         */
        bool isFile = false;

        /**
         * @brief Mime type of an argument value. This field makes sense only if isFile is true.
         */
        std::string mimeType = "text/plain";

        /**
         * @brief Should be set if an argument value hold some file contents
         */
        std::string fileName;
    };

}

#endif // TGBOT_HTTPPARAMETER_H
