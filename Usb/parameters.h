#ifndef PARAMETERS_H
#define PARAMETERS_H


class Parameters
{
public:
    Parameters();

    enum class Task {
        onlyCopy,
        onlyKill,
        killAndCopy,
        createConfig,
        createConfigAndRead,
    };
};

#endif // PARAMETERS_H
