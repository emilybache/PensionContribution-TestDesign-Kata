import {Employee} from "./Employee";

export interface DatabaseAccess {
  getEmployeeById(employeeId: number): Employee;

  lookupValue(namedConstant: string): number;
}
