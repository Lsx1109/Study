graph TD
    A[用户输入 num1, num2, num3] -->|输入| B[比较 num1, num2, num3]
    B -->|num1 >= num2 && num1 >= num3| C1{ }
    C1 -->|true| D1[num1 >= num2]
    D1 -->|true| E1[输出 num1, num2, num3]
    D1 -->|false| F1[输出 num1, num3, num2]
    C1 -->|false| G1[num2 >= num3]
    G1 -->|true| H1[输出 num2, num3, num1]
    G1 -->|false| I1[输出 num3, num2, num1]
    B -->|num2 >= num1 && num2 >= num3| C2{ }
    C2 -->|true| D2[num2 >= num1]
    D2 -->|true| E2[输出 num2, num1, num3]
    D2 -->|false| F2[输出 num2, num3, num1]
    C2 -->|false| G2[num1 >= num3]
    G2 -->|true| H2[输出 num1, num3, num2]
    G2 -->|false| I2[输出 num3, num1, num2]
    B -->|num3 >= num1 && num3 >= num2| C3{ }
    C3 -->|true| D3[num3 >= num1]
    D3 -->|true| E3[输出 num3, num1, num2]
    D3 -->|false| F3[输出 num3, num2, num1]
    C3 -->|false| G3[num1 >= num2]
    G3 -->|true| H3[输出 num1, num2, num3]
    G3 -->|false| I3[输出 num2, num1, num3]
