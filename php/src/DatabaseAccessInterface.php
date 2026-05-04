<?php

declare(strict_types=1);

namespace PensionContribution;

interface DatabaseAccessInterface
{
    public function getEmployeeById(int $employeeId): Employee;

    public function lookupValue(string $namedConstant): float;
}
