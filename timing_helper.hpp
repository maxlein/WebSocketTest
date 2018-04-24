#include <chrono>
#include <vector>
#include <climits>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

class TimingHelper{

public:

    TimingHelper(){};

    static long getDurationFromGivenStartTillNow(long start){
        long end = getCurrentTimeInMicroSec().count();
        //std::cout << "start: " << start << ", end: " << end << endl;
        return end - start;
    }

    static long getDurationFromGivenStartTillNow(string start){
        return getDurationFromGivenStartTillNow(convertStringTimeToLong(start));
    }

    static microseconds getCurrentTimeInMicroSec(){
        return duration_cast< microseconds >( system_clock::now().time_since_epoch() );
    }

    static string getCurrentTimeInMicroSecAsString(){
        microseconds ms = getCurrentTimeInMicroSec();
        //std::cout << "now: " << ms.count() << std::endl;
        return std::to_string(ms.count());
    }

    static long convertStringTimeToLong(const string& time){
        long time_l = 0;
        try {
            time_l = std::stol( time );
        } catch(const std::exception& e) {
            std::cout << "Exception at convertStringTimeToLong(): " << e.what()<< '\n';
        }
        return time_l;
    }

    void saveDurationFromGivenStartTillNow(string time){
        long duration = getDurationFromGivenStartTillNow(time);
        durations_.push_back(duration);
    }

    void clearStatistics(){
        durations_.clear();
    }

    void printStatistics(){
        if(durations_.size() == 0){
            cerr << "Cant print statistics when no durations are set!" << endl;
            return;
        }

        double mean = 0;
        long min = LONG_MAX;
        long max = 0;
        for(auto duration : durations_){
            mean += duration;
            min = duration < min ? duration : min;
            max = duration > max ? duration : max;
        }

        mean = mean / durations_.size();
        printf("Statistics [µs]: min: %ld max: %ld mean: %.2f\n", min, max, mean);
    }

    long getDurationInMicroSec(){
        //std::cout << "start_time_: " << start_time_ << ", end_time_: " << end_time_ << endl;
        return end_time_ - start_time_;
    }

    void setStartTime(){
        start_time_ = getCurrentTimeInMicroSec().count();
    }

    void setStartTime(const long& time){
        start_time_ = time;
    }

    void setEndTime(){
        end_time_ = getCurrentTimeInMicroSec().count();
    }

    void setEndTime(const long& time){
        end_time_ = time;
    }

private:

    long start_time_;
    long end_time_;
    vector<long> durations_;
};
