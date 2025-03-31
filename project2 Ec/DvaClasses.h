#ifndef DVACLASSES_H
#define DVACLASSES_H

class Battle {
    private:
        int botsPower[10];
        int botsCount;
        float bossPower;
    public:
        Battle(int botsCount, float bossPower, int* botsPower);
        float matrix_power();

    // so Mech can read private members
    friend class Mech;
};

class Mech {
    private:
        float defenseMatrix;
        int microMissiles;
    public:
        Mech();
        // micro_missile(Battle&) function
        float micro_missile(const Battle& b);
        // load() function
        void load(float matrixPowerRequired, float missilePowerRequired);
        // getters
        double get_defenseMatrix() const;
        int get_missiles() const;
};

#endif // DVACLASSES_H