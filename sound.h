// constants definiton
#define RATE 16000		// 16000 samples per second
#define DUR 5
#define RCMD "arecord -r16000 -c1 -f S16_LE -d5 test.wav"
// data structures
struct WAVHDR
{
	char ChunkID[4];	// it has to be RIFF
	int ChunkSize;		// 4 byte number
	char Format[4];		// it has to be WAVE

	char Subchunk1ID[4];	// it has to be fmt
	int Subchunk1Size;	// PCM = 16
	short AudioFormat; 	// should be 1
	short NumChannels;	// should be 1 for mono mic
	int SampleRate;		// 16000
	int ByteRate;		// 16000*NumChannels*BitsPerSample/8
	short BlockAlign;	// NumChannels*BitsPerChample/8
	short BitsPerSample;	// in our app, 16 (-f S16_LE)

	char Subchunk2ID[4];	// "data
	int Subchunk2Size;
};
// function declarations
void displayWAVHDR(struct WAVHDR);
void showID(char *,char *);
void displayWAVDATA(short []);
