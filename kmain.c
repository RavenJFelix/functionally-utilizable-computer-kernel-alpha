void kmain()
{
	//Have the caharcter point to the first text cell
	//of the video memory
	char* video_memory = (char*) 0x000b8000;
	// Store the character F at the top left 
	*video_memory = 'F';
	video_memory[2] = 'U';
}
