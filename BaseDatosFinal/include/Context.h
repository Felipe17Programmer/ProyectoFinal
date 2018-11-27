#ifndef CONTEXT_H
#define CONTEXT_H


class Context
{
    private:
        StrategyInterface *_strategy;

    public:
        /*Context(StrategyInterface *strategy):_strategy(strategy)
        {
        }*/

        void set_strategy(StrategyInterface *strategy)
        {
            _strategy = strategy;
        }

        void execute()
        {
            _strategy->execute();
        }
};

#endif // CONTEXT_H
