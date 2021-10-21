#pragma once

class InteractiveObject {
public:
    virtual ~InteractiveObject() = default;

    // Pattern: Prototype
    virtual InteractiveObject* clone() = 0;
};