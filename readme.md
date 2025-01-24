# Matrix Inverse Calculation Project

## 1. VSCode Community Edition Installation

### Prerequisites
- Windows 10/11
- Minimum 4GB RAM
- 2.5GB disk space

### Installation Steps
1. Download VSCode Installer
   - Visit [https://code.visualstudio.com/download](https://code.visualstudio.com/download)
   - Choose "Windows" version

2. Run Installer
   - Double-click downloaded `.exe` file
   - Accept license agreement
   - Select installation location
   - Choose additional tasks:
     * Add to PATH
     * Create desktop icon
     * Create Start Menu folder

3. Install C/C++ Extensions
   - Open VSCode
   - Click Extensions (Ctrl+Shift+X)
   - Search and install:
     * C/C++ Extension Pack
     * C/C++ Intellisense

## 2. Project Setup

### Compiler Installation
Download MinGW-w64
   - Visit [https://sourceforge.net/projects/mingw-w64/](https://sourceforge.net/projects/mingw-w64/)
   - Download installer
   - Select architecture: x86_64
   - Add to system PATH

## 3. Matrix Inverse Calculation Algorithm

### Steps
1. Calculate Determinant
2. Create Cofactor Matrix
3. Generate Adjoint Matrix
4. Compute Inverse Matrix

### Code Example
```cpp
// Matrix inverse calculation
float determinant = /* calculated value */;
float kofaktor[3][3]; // Cofactor matrix
float setAdjoin[3][3]; // Adjoint matrix
float setInvers[3][3]; // Inverse matrix
```

#### Calculate Step In
Matrix Inverse Calculation Steps
1. Determinant Calculation

Compute matrix determinant
Check if determinant ≠ 0

2. Cofactor Matrix

Calculate each element using minor determinants
Alternate signs following checkerboard pattern
Formula: Cᵢⱼ = (−1)ⁱ⁺ʲ * Minor(i,j)

3. Adjoint Matrix

Transpose cofactor matrix
Swap rows and columns

4. Inverse Matrix

Divide adjoint matrix by determinant
Formula: A⁻¹ = (1/det(A)) * Adj(A)

Key Constraints

Determinant must not be zero
Only works for square matrices