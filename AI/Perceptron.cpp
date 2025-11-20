//C++ 퍼셉트론 (Perceptron)
//이진 분류 배우기 - 입력 x1, x2 → 출력 0/1 을 학습하는 간단한 구조.

#include <iostream>
#include <vector>
using namespace std;

// 퍼셉트론: 간단한 이진 분류기
class Perceptron {
private:
    vector<double> weights;
    double bias;
    double lr; // learning rate

public:
    Perceptron(int input_size, double lr=0.1) : lr(lr) {
        weights.resize(input_size, 0.0);
        bias = 0.0;
    }

    // 활성화 함수: 계단함수
    int activation(double x) {
        return (x >= 0) ? 1 : 0;
    }

    // 예측 함수
    int predict(const vector<double>& x) {
        double sum = bias;
        for (int i = 0; i < x.size(); i++)
            sum += x[i] * weights[i];
        return activation(sum);
    }

    // 훈련 (단순 퍼셉트론 규칙)
    void train(const vector<vector<double>>& X, const vector<int>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; epoch++) {
            for (int i = 0; i < X.size(); i++) {
                int pred = predict(X[i]);
                int error = y[i] - pred;

                for (int j = 0; j < weights.size(); j++)
                    weights[j] += lr * error * X[i][j];

                bias += lr * error;
            }
        }
    }
};

int main() {
    // AND 문제 학습
    vector<vector<double>> X = {
        {0,0}, {0,1}, {1,0}, {1,1}
    };
    vector<int> y = {0, 0, 0, 1};

    Perceptron p(2);
    p.train(X, y, 20);

    cout << p.predict({0,0}) << endl;
    cout << p.predict({0,1}) << endl;
    cout << p.predict({1,0}) << endl;
    cout << p.predict({1,1}) << endl;
}
