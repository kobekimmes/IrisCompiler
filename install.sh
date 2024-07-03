#!/bin/bash

# Compile the project
make build

# Move the executable to /usr/local/bin
sudo mv iris /usr/local/bin

# Retrieve current directory PATH
INSTALL_PATH=$(pwd)

# Add the directory containing the iris executable to PATH in ~/.zshrc
if ! grep -q "$INSTALL_PATH" ~/.zshrc; then
    echo "export PATH=\"\$PATH:$INSTALL_PATH\"" >> ~/.zshrc
    echo "Added $INSTALL_PATH to PATH in ~/.zshrc."
    # Reload ~/.zshrc to apply changes
    source ~/.zshrc
else
    echo "$INSTALL_PATH is already in PATH in ~/.zshrc."
fi

echo "Installation complete. You can now use the 'iris' command to invoke the Iris compiler."
