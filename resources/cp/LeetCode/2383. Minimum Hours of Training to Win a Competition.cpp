class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int en = initialEnergy;
        int ex = initialExperience;
        int total = 0;
        for (int i = 0; i < energy.size(); ++i) {
            if (en <= energy[i]) {
                total += energy[i] - en + 1;
                en = energy[i] + 1;
            }
            if (ex <= experience[i]) {
                total += experience[i] - ex + 1;
                ex = experience[i] + 1; 
            }
            en -= energy[i];
            ex += experience[i];
        }
        return total;
    }
};