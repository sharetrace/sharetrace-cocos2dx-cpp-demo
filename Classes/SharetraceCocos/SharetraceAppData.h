//
//  SharetraceAppData.hpp
//  cocos-cpp
//
// Created by Sharetrace on 2020/1/26.
//

#ifndef SharetraceAppData_h
#define SharetraceAppData_h

#include <string>

namespace sharetrace2dx {
    
    class SharetraceAppData {
        
    private:
        std::string paramsData;
        std::string channel;
        
    public:
        
        SharetraceAppData() {};
        
        SharetraceAppData(std::string paramsData, std::string channel) {
            this->paramsData = paramsData;
            this->channel = channel;
        }
        
        std::string getChannel();
        
        std::string getParamsData();
    };

}


#endif /* SharetraceAppData_h */
