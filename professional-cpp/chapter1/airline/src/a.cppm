module;
export module A;
class Secret {
public:
    Secret(int a): _a{a}{}
    int _a;
};

export Secret getSecret() {
    return Secret{1};
}