#include <functional>
#include <cmath>
#include <random>

static std::random_device device;
static std::mt19937 generator(device());
static std::uniform_real_distribution<double> range(0,1);

bool take(double old_val, double new_val, double temp){
    if(new_val > old_val)return true;
    double diff = abs(old_val - new_val);
    double n = exp( - diff / temp);
    return range(generator) > n;
}

template<class T>
T annealing(std::function<double(T)> goal, T initial, std::function<T(T)> neighbour,
            std::function<double(int)> temperature, std::function<bool(std::vector<double>)> domain, int iterations) {
    T current_point = initial;
    T best_point = initial;
    for (int i = 0; i < iterations; i++) {
        T new_point = neighbour(current_point);
        if(domain(new_point) && take(goal(current_point), goal(new_point), temperature(i))){
            current_point = new_point;
            if(goal(current_point) > goal(best_point)){
                best_point = current_point;
            }
        }
    }
    return best_point;
}

double zero_temp(int i){
    return 0;
}

template<class T>
T lazy_hill_climb(std::function<double(T)> goal, T initial, std::function<T(T)> neighbour, std::function<bool(std::vector<double>)> domain, int iterations){

    return annealing(goal, initial, neighbour, zero_temp, domain, iterations);
}

std::vector<double> simple_neighbour(std::vector<double> point){
    static std::random_device device;
    static std::mt19937 generator(device());
    static std::uniform_real_distribution<double> range(-0.2,0.2);
    for(int i=0;i<point.size();i++){
        point[i] += range(generator);
    }
    return point;
}

double simple_temp(int i){
    return 100000.0 / i;
}