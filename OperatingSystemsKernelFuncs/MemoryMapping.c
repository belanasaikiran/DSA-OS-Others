#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define NUM_RESOURCES 30000000

struct Resource {
  int id;
  char data[64];
} Resource;

int main() {

  // THe below variable hold the size required for out program - for all the
  // resources
  size_t size = sizeof(Resource) * NUM_RESOURCES;

  // 1. open or create a file that can back  your memory
  int fd = open("Resources.dat", O_RDWR | O_CREAT, 0666);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // 2. resize the file to fit your resource array
  if (ftruncate(fd, size) == -1) {
    // failed to resize
    perror("failed to allocate <- ftruncate");
    return 1;
  }

  // Here comes the hero. MMAP
  // 3. Map the file into memory
  struct Resource *resources =
      (struct Resource *)mmap(NULL, // let OS choose the address
                              size, // total size to map
                              PROT_READ | PROT_WRITE, // read and write access
                              MAP_SHARED, // changes are shared with the file
                              fd,         // File descriptor for `Resources.dat`
                              0           // offse int o the file
      );

  if (resources == MAP_FAILED) {
    perror("mmap failed");
    return 1;
  }

  // 4. Use it like a normal array
  resources[0].id = 1001;
  snprintf(resources[0].data, sizeof(resources[0].data), "Resources number %d",
           resources[0].id);

  printf("ID: %id, Data: %s\n", resources[0].id, resources[0].data);

  // SIMULATION:
  // Simulating by writing to first and last few resources
  printf("************************\n");
  printf("Starting the Simulation\n");
  printf("************************\n");

  printf("Writing to first 5 resources and last 5 resources... \n");
  for (int i = 0; i < 5; i++) {
    resources[i].id = i;
    snprintf(resources[i].data, sizeof(resources[i].data), "Resource #%d", i);
  }

  for (int i = NUM_RESOURCES - 5; i < NUM_RESOURCES; i++) {
    resources[i].id = i;
    snprintf(resources[i].data, sizeof(resources[i].data), "Resource #%d", i);
  }

  printf(" ✔️ VERIFYING VALUES: \n");

  for (int i = 0; i < 5; i++) {
    printf("ID: %d, Data: %s - ", resources[i].id, resources[i].data);
    char veri[32];
    snprintf(veri,sizeof(veri), "#%d", resources[i].id);
    // printf("veri: %s", veri);
    if(strcmp(resources[i].data, veri) == 0){
        printf("✔️\n");
    } else{
        printf("❌\n");
    }

  }

  for (int i = NUM_RESOURCES - 5; i < NUM_RESOURCES; i++) {
    printf("ID: %d, Data: %s - ", resources[i].id, resources[i].data);
    char veri[32];
    snprintf(veri,sizeof(veri), "#%d", resources[i].id);
    if(strcmp(resources[i].data, veri) == 0){
        printf("✔️\n");
    } else{
        printf("❌\n");
    }
  }
  // 5. Clean Up
  munmap(resources, size);
  close(fd);

  return 0;
}
