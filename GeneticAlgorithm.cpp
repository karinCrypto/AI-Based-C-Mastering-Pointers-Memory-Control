#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>

// ===============================
// DNA 구조 (Genetic Algorithm (유전 알고리즘) 기본 구성 요소 5개 전부 포함)
//DNA = 유전자 (문자열 기반, 숫자 기반으로 변경 가능)
//Fitness function = 목표와 얼마나 가까운지
//Selection = 룰렛휠 방식
//Crossover = 중간 지점 기준 교차
//Mutation = 랜덤 변이
//Population = 세대 반복

//게임이 뜨려면?
// 1) C++ + SDL2 / SFML / OpenGL 이런 그래픽 라이브러리를 이용해야 “창(Window)”이 뜬다.
// 2) 유전 알고리즘 + 게임 엔진 유전 알고리즘으로 캐릭터 행동을 학습시키고
// SDL2 같은 엔진에서 캐릭터가 움직여야 → 눈에 보이는 게임 화면이 생겨.

    
// ===============================

using namespace std;

// 난수 생성기
random_device rd;
mt19937 gen(rd());

// ===============================
// 1. DNA 구조
// ===============================
struct DNA {
    string genes;   // 유전자(문자열)
    double fitness; // 적합도

    DNA(int length) {
        genes.resize(length);
        randomizeGenes();
        fitness = 0.0;
    }

    // 랜덤 문자 생성
    void randomizeGenes() {
        uniform_int_distribution<> dist(32, 126); // ASCII printable
        for (auto &c : genes)
            c = static_cast<char>(dist(gen));
    }

    // 적합도 계산 (목표 문자열과 얼마나 비슷한가)
    void calcFitness(const string& target) {
        int score = 0;
        for (int i = 0; i < genes.size(); i++) {
            if (genes[i] == target[i])
                score++;
        }
        fitness = (double)score / target.size(); // 0.0 ~ 1.0
    }

    // ===============================
    // 2. Crossover (교차)
    // ===============================
    DNA crossover(const DNA& partner) {
        DNA child(genes.size());
        uniform_int_distribution<> dist(0, genes.size() - 1);
        int midpoint = dist(gen);

        for (int i = 0; i < genes.size(); i++) {
            if (i < midpoint) child.genes[i] = genes[i];
            else child.genes[i] = partner.genes[i];
        }
        return child;
    }

    // ===============================
    // 3. Mutation (돌연변이)
    // ===============================
    void mutate(double mutationRate) {
        uniform_real_distribution<> chance(0.0, 1.0);
        uniform_int_distribution<> dist(32, 126);

        for (auto &c : genes) {
            if (chance(gen) < mutationRate) {
                c = static_cast<char>(dist(gen));
            }
        }
    }
};

// ===============================
// 4. Population (개체군)
// ===============================
class Population {
private:
    vector<DNA> population;
    string target;
    double mutationRate;
    int popSize;

public:
    Population(string target, int size, double mutationRate)
        : target(target), popSize(size), mutationRate(mutationRate)
    {
        for (int i = 0; i < popSize; i++)
            population.emplace_back(target.size());
    }

    // 적합도 계산
    void evaluate() {
        for (auto &dna : population)
            dna.calcFitness(target);
    }

    // 자연 선택(Selection)
    DNA selectParent() {
        // 룰렛 선택 방식: fitness 기반 확률 선택
        double totalFitness = 0.0;
        for (auto& dna : population)
            totalFitness += dna.fitness;

        uniform_real_distribution<> dist(0.0, totalFitness);
        double pick = dist(gen);
        double running = 0.0;

        for (auto& dna : population) {
            running += dna.fitness;
            if (running >= pick)
                return dna;
        }
        return population.back();
    }

    // 세대 업데이트
    void generate() {
        vector<DNA> newPopulation;
        newPopulation.reserve(popSize);

        for (int i = 0; i < popSize; i++) {
            // 부모 2명 선택
            DNA parentA = selectParent();
            DNA parentB = selectParent();

            // 교차
            DNA child = parentA.crossover(parentB);

            // 변이
            child.mutate(mutationRate);

            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    // 최고 개체 출력
    string getBest() {
        DNA* best = &population[0];
        for (auto &dna : population) {
            if (dna.fitness > best->fitness)
                best = &dna;
        }
        return best->genes;
    }

    bool isCompleted() {
        return getBest() == target;
    }
};

// ===============================
// 메인 실행
// ===============================
int main() {
    string target = "Hello Genetic Algorithm!";
    int populationSize = 300;
    double mutationRate = 0.01;

    Population pop(target, populationSize, mutationRate);

    int generation = 0;

    while (!pop.isCompleted()) {
        pop.evaluate();
        cout << "Generation " << generation
             << " | Best: " << pop.getBest() << endl;

        pop.generate();
        generation++;

        if (generation > 5000) break; // 안전장치
    }

    cout << "\nFinal Answer: " << pop.getBest() << endl;

    return 0;
}
