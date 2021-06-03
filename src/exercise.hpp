#ifndef BATTLE_DEV_EXERCISE_HPP
#define BATTLE_DEV_EXERCISE_HPP

#include <string>

class Exercise {
public:
    Exercise() = default;
    virtual void main() = 0;
};

class ContestExerciseImpl : public Exercise {
public:
    ContestExerciseImpl();
    void main() override;
};

void localPrint(std::string const& str);


#endif //BATTLE_DEV_EXERCISE_HPP
