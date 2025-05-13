#include <iostream>
#include <vector>
#include <memory>

// Abstract base class for all Behavior Tree nodes
class Node {
public:
    virtual bool execute() = 0;
};

// Leaf Node: Attack Player
class AttackPlayer : public Node {
public:
    bool execute() override {
        std::cout << "Attacking player!\n";
        return true; // Succeeds
    }
};

// Leaf Node: Chase Player
class ChasePlayer : public Node {
public:
    bool execute() override {
        std::cout << "Chasing player...\n";
        return true; // Succeeds
    }
};

// Leaf Node: Patrol Area
class PatrolArea : public Node {
public:
    bool execute() override {
        std::cout << "Patrolling the area...\n";
        return true; // Succeeds
    }
};

// Composite Node: Sequence (Executes all children in order)
class Sequence : public Node {
private:
    std::vector<std::shared_ptr<Node>> children;

public:
    void addChild(std::shared_ptr<Node> child) {
        children.push_back(child);
    }

    bool execute() override {
        for (auto& child : children) {
            if (!child->execute()) {
                return false; // Fail if any child fails
            }
        }
        return true;
    }
};

// Composite Node: Selector (Tries each child until one succeeds)
class Selector : public Node {
private:
    std::vector<std::shared_ptr<Node>> children;

public:
    void addChild(std::shared_ptr<Node> child) {
        children.push_back(child);
    }

    bool execute() override {
        for (auto& child : children) {
            if (child->execute()) {
                return true; // Succeed if any child succeeds
            }
        }
        return false;
    }
};

int main() {
    // Create Behavior Tree
    auto root = std::make_shared<Selector>();

    // Create sequence node for aggressive behavior
    auto aggressiveSequence = std::make_shared<Sequence>();
    aggressiveSequence->addChild(std::make_shared<ChasePlayer>());
    aggressiveSequence->addChild(std::make_shared<AttackPlayer>());

    // Add patrol as fallback if not aggressive
    root->addChild(aggressiveSequence);
    root->addChild(std::make_shared<PatrolArea>());

    // Run Behavior Tree
    root->execute();

    return 0;
}
