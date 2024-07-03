#!/bin/bash

# Compile the project
make build

# Move the executable to /usr/local/bin
sudo mv iris /usr/local/bin

# Add to path
echo 'export PATH="$PATH:/path/to/your/script"' >> ~/.zshrc

# Reload to apply changes
source ~/.zshrc

echo "Installation complete. You can now use the 'iris' command to invoke the Iris compiler."
