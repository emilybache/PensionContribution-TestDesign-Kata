<?php

declare(strict_types=1);

namespace PensionContribution;

final readonly class Employee
{
    public function __construct(
        private float $annualSalary,
        private int $tenure,
        private SeniorityLevelInterface $seniorityLevel
    ) {
    }

    public function getTenure(): int
    {
        return $this->tenure;
    }

    public function getSeniority(): SeniorityLevelInterface
    {
        return $this->seniorityLevel;
    }

    public function getAnnualSalary(): float
    {
        return $this->annualSalary;
    }
}
