/*
 *  Simple event decoder
 */

static char *event_names[256] = {
	/* 0   */	"System",
	/* 1   */	"Note",
	/* 2   */	"Note On",
	/* 3   */	"Note Off",
	/* 4   */	"Reserved 4",
	/* 5   */	"Reserved 5",
	/* 6   */	"Reserved 6",
	/* 7   */	"Reserved 7",
	/* 8   */	"Reserved 8",
	/* 9   */	"Reserved 9",
	/* 10   */	"KeyPress",
	/* 11   */	"Controller",
	/* 12   */	"Program Change",
	/* 13   */	"Channel Pressure",
	/* 14   */	"Pitchbend",
	/* 15   */	"Control14",
	/* 16   */	"Nonregparam",
	/* 17   */	"Regparam",
	/* 18   */	"Reserved 18",
	/* 19   */	"Reserved 19",
	/* 20   */	"Song Position",
	/* 21   */	"Song Select",
	/* 22   */	"Clock",
	/* 23   */	"Start",
	/* 24   */	"Continue",
	/* 25   */	"Stop",
	/* 26   */	"Qframe",
	/* 27   */	"Reserved 27",
	/* 28   */	"Reserved 28",
	/* 29   */	"Reserved 29",
	/* 30   */	"Tempo",
	/* 31   */	"SMF Time Signature",
	/* 32   */	"SMF Key Signature",
	/* 33   */	"Reserved 33",
	/* 34   */	"Reserved 34",
	/* 35   */	"Reserved 35",
	/* 36   */	"Reserved 36",
	/* 37   */	"Reserved 37",
	/* 38   */	"Reserved 38",
	/* 39   */	"Reserved 39",
	/* 40   */	"System Exclusive",
	/* 41   */	"Heart Beat",
	/* 42   */	"Reserved 42",
	/* 43   */	"Reserved 43",
	/* 44   */	"Reserved 44",
	/* 45   */	"Reserved 45",
	/* 46   */	"Reserved 46",
	/* 47   */	"Reserved 47",
	/* 48   */	"Reserved 48",
	/* 49   */	"Reserved 49",
	/* 50   */	"Heart Beat (Active sensing)",
	/* 51   */	"Echo",
	/* 52   */	"Reserved 52",
	/* 53   */	"Reserved 53",
	/* 54   */	"Reserved 54",
	/* 55   */	"Reserved 55",
	/* 56   */	"Reserved 56",
	/* 57   */	"Reserved 57",
	/* 58   */	"Reserved 58",
	/* 59   */	"Reserved 59",
	/* 60   */	"Client Start",
	/* 61   */	"Client Exit",
	/* 62   */	"Client Change",
	/* 63   */	"Port Start",
	/* 64   */	"Port Exit",
	/* 65   */	"Port Change",
	/* 66   */	"Reserved 66",
	/* 67   */	"Reserved 67",
	/* 68   */	"Reserved 68",
	/* 69   */	"Reserved 69",
	/* 70   */	"Reserved 70",
	/* 71   */	"Reserved 71",
	/* 72   */	"Reserved 72",
	/* 73   */	"Reserved 73",
	/* 74   */	"Reserved 74",
	/* 75   */	"Reserved 75",
	/* 76   */	"Reserved 76",
	/* 77   */	"Reserved 77",
	/* 78   */	"Reserved 78",
	/* 79   */	"Reserved 79",
	/* 80   */	"Sample Select",
	/* 81   */	"Sample Start",
	/* 82   */	"Sample Stop",
	/* 83   */	"Sample Frequency",
	/* 84   */	"Sample Volume",
	/* 85   */	"Sample Loop",
	/* 86   */	"Sample Position",
	/* 87   */	"Reseved 87",
	/* 88   */	"Reseved 88",
	/* 89   */	"Reseved 89",
	/* 90   */	"Reseved 90",
	/* 91   */	"Reseved 91",
	/* 92   */	"Reseved 92",
	/* 93   */	"Reseved 93",
	/* 94   */	"Reseved 94",
	/* 95   */	"Reseved 95",
	/* 96   */	"Reseved 96",
	/* 97   */	"Reseved 97",
	/* 98   */	"Reseved 98",
	/* 99   */	"Reseved 99",
	/* 100  */	"Reseved 100",
	/* 101  */	"Reseved 101",
	/* 102  */	"Reseved 102",
	/* 103  */	"Reseved 103",
	/* 104  */	"Reseved 104",
	/* 105  */	"Reseved 105",
	/* 106  */	"Reseved 106",
	/* 107  */	"Reseved 107",
	/* 108  */	"Reseved 108",
	/* 109  */	"Reseved 109",
	/* 100  */	"Reserved 100"
	/* 101  */	"Reserved 101"
	/* 102  */	"Reserved 102"
	/* 103  */	"Reserved 103"
	/* 104  */	"Reserved 104"
	/* 105  */	"Reserved 105"
	/* 106  */	"Reserved 106"
	/* 107  */	"Reserved 107"
	/* 108  */	"Reserved 108"
	/* 109  */	"Reserved 109"
	/* 110  */	"Reserved 110"
	/* 111  */	"Reserved 111"
	/* 112  */	"Reserved 112"
	/* 113  */	"Reserved 113"
	/* 114  */	"Reserved 114"
	/* 115  */	"Reserved 115"
	/* 116  */	"Reserved 116"
	/* 117  */	"Reserved 117"
	/* 118  */	"Reserved 118"
	/* 119  */	"Reserved 119"
	/* 120  */	"Reserved 120"
	/* 121  */	"Reserved 121"
	/* 122  */	"Reserved 122"
	/* 123  */	"Reserved 123"
	/* 124  */	"Reserved 124"
	/* 125  */	"Reserved 125"
	/* 126  */	"Reserved 126"
	/* 127  */	"Reserved 127"
	/* 128  */	"Reserved 128"
	/* 129  */	"Reserved 129"
	/* 130  */	"Reserved 130"
	/* 131  */	"Reserved 131"
	/* 132  */	"Reserved 132"
	/* 133  */	"Reserved 133"
	/* 134  */	"Reserved 134"
	/* 135  */	"Reserved 135"
	/* 136  */	"Reserved 136"
	/* 137  */	"Reserved 137"
	/* 138  */	"Reserved 138"
	/* 139  */	"Reserved 139"
	/* 140  */	"Reserved 140"
	/* 141  */	"Reserved 141"
	/* 142  */	"Reserved 142"
	/* 143  */	"Reserved 143"
	/* 144  */	"Reserved 144"
	/* 145  */	"Reserved 145"
	/* 146  */	"Reserved 146"
	/* 147  */	"Reserved 147"
	/* 148  */	"Reserved 148"
	/* 149  */	"Reserved 149"
	/* 150  */	"Reserved 150"
	/* 151  */	"Reserved 151"
	/* 152  */	"Reserved 152"
	/* 153  */	"Reserved 153"
	/* 154  */	"Reserved 154"
	/* 155  */	"Reserved 155"
	/* 156  */	"Reserved 156"
	/* 157  */	"Reserved 157"
	/* 158  */	"Reserved 158"
	/* 159  */	"Reserved 159"
	/* 160  */	"Reserved 160"
	/* 161  */	"Reserved 161"
	/* 162  */	"Reserved 162"
	/* 163  */	"Reserved 163"
	/* 164  */	"Reserved 164"
	/* 165  */	"Reserved 165"
	/* 166  */	"Reserved 166"
	/* 167  */	"Reserved 167"
	/* 168  */	"Reserved 168"
	/* 169  */	"Reserved 169"
	/* 170  */	"Reserved 170"
	/* 171  */	"Reserved 171"
	/* 172  */	"Reserved 172"
	/* 173  */	"Reserved 173"
	/* 174  */	"Reserved 174"
	/* 175  */	"Reserved 175"
	/* 176  */	"Reserved 176"
	/* 177  */	"Reserved 177"
	/* 178  */	"Reserved 178"
	/* 179  */	"Reserved 179"
	/* 180  */	"Reserved 180"
	/* 181  */	"Reserved 181"
	/* 182  */	"Reserved 182"
	/* 183  */	"Reserved 183"
	/* 184  */	"Reserved 184"
	/* 185  */	"Reserved 185"
	/* 186  */	"Reserved 186"
	/* 187  */	"Reserved 187"
	/* 188  */	"Reserved 188"
	/* 189  */	"Reserved 189"
	/* 190  */	"Reserved 190"
	/* 191  */	"Reserved 191"
	/* 192  */	"Reserved 192"
	/* 193  */	"Reserved 193"
	/* 194  */	"Reserved 194"
	/* 195  */	"Reserved 195"
	/* 196  */	"Reserved 196"
	/* 197  */	"Reserved 197"
	/* 198  */	"Reserved 198"
	/* 199  */	"Reserved 199"
	/* 200  */	"Reserved 200"
	/* 201  */	"Reserved 201"
	/* 202  */	"Reserved 202"
	/* 203  */	"Reserved 203"
	/* 204  */	"Reserved 204"
	/* 205  */	"Reserved 205"
	/* 206  */	"Reserved 206"
	/* 207  */	"Reserved 207"
	/* 208  */	"Reserved 208"
	/* 209  */	"Reserved 209"
	/* 210  */	"Reserved 210"
	/* 211  */	"Reserved 211"
	/* 212  */	"Reserved 212"
	/* 213  */	"Reserved 213"
	/* 214  */	"Reserved 214"
	/* 215  */	"Reserved 215"
	/* 216  */	"Reserved 216"
	/* 217  */	"Reserved 217"
	/* 218  */	"Reserved 218"
	/* 219  */	"Reserved 219"
	/* 220  */	"Reserved 220"
	/* 221  */	"Reserved 221"
	/* 222  */	"Reserved 222"
	/* 223  */	"Reserved 223"
	/* 224  */	"Reserved 224"
	/* 225  */	"Reserved 225"
	/* 226  */	"Reserved 226"
	/* 227  */	"Reserved 227"
	/* 228  */	"Reserved 228"
	/* 229  */	"Reserved 229"
	/* 230  */	"Reserved 230"
	/* 231  */	"Reserved 231"
	/* 232  */	"Reserved 232"
	/* 233  */	"Reserved 233"
	/* 234  */	"Reserved 234"
	/* 235  */	"Reserved 235"
	/* 236  */	"Reserved 236"
	/* 237  */	"Reserved 237"
	/* 238  */	"Reserved 238"
	/* 239  */	"Reserved 239"
	/* 240  */	"Reserved 240"
	/* 241  */	"Reserved 241"
	/* 242  */	"Reserved 242"
	/* 243  */	"Reserved 243"
	/* 244  */	"Reserved 244"
	/* 245  */	"Reserved 245"
	/* 246  */	"Reserved 246"
	/* 247  */	"Reserved 247"
	/* 248  */	"Reserved 248"
	/* 249  */	"Reserved 249"
	/* 250  */	"Reserved 250"
	/* 251  */	"Reserved 251"
	/* 252  */	"Reserved 252"
	/* 253  */	"Reserved 253"
	/* 254  */	"Reserved 254"
	/* 255  */	"Reserved 255"
};

int decode_event(snd_seq_event_t * ev)
{
	char *space = "         ";

	printf("EVENT>>> Type = %d, flags = 0x%x", ev->type, ev->flags);
	switch (ev->flags & SND_SEQ_TIME_STAMP_MASK) {
		case SND_SEQ_TIME_STAMP_TICK:
			printf(", time = %d ticks",
			       ev->time.tick);
			break;
		case SND_SEQ_TIME_STAMP_REAL:
			printf(", time = %d.%09d",
			       (int)ev->time.real.tv_sec,
			       (int)ev->time.real.tv_nsec);
			break;
	}
	printf("\n%sSource = %d.%d.%d.%d, dest = %d.%d.%d.%d\n",
	       space,
	       ev->source.queue,
	       ev->source.client,
	       ev->source.port,
	       ev->source.channel,
	       ev->dest.queue,
	       ev->dest.client,
	       ev->dest.port,
	       ev->dest.channel);

	printf("%sEvent = %s", space, event_names[ev->type]);
	/* decode actual event data... */
	switch (ev->type) {
		case SND_SEQ_EVENT_NOTE:
			printf("; note=%d, velocity=%d, duration=%d\n",
			       ev->data.note.note,
			       ev->data.note.velocity,
			       ev->data.note.duration);
			break;

		case SND_SEQ_EVENT_NOTEON:
		case SND_SEQ_EVENT_NOTEOFF:
			printf("; note=%d, velocity=%d\n",
			       ev->data.note.note,
			       ev->data.note.velocity);
			break;
		
		case SND_SEQ_EVENT_KEYPRESS:
		case SND_SEQ_EVENT_CONTROLLER:
			printf("; param=%i, value=%i\n",
				ev->data.control.param,
				ev->data.control.value);
			break;

		case SND_SEQ_EVENT_PGMCHANGE:
			printf("; program=%i\n", ev->data.control.value);
			break;
			
		case SND_SEQ_EVENT_CHANPRESS:
		case SND_SEQ_EVENT_PITCHBEND:
			printf("; value=%i\n", ev->data.control.value);
			break;
			
		case SND_SEQ_EVENT_SYSEX:
			{
				unsigned char *sysex = (unsigned char *) ev + sizeof(snd_seq_event_t);
				int c;

				printf("; len=%d [", ev->data.ext.len);

				for (c = 0; c < ev->data.ext.len; c++) {
					printf("%02x%s", sysex[c], c < ev->data.ext.len - 1 ? ":" : "");
				}
				printf("]\n");
			}
			break;
			
		case SND_SEQ_EVENT_QFRAME:
			printf("; frame=%i\n", ev->data.control.value);
			break;
			
		case SND_SEQ_EVENT_CLOCK:
		case SND_SEQ_EVENT_START:
		case SND_SEQ_EVENT_CONTINUE:
		case SND_SEQ_EVENT_STOP:
			printf("; queue = %i, client = %i\n", ev->data.addr.queue, ev->data.addr.client);
			break;

		case SND_SEQ_EVENT_HEARTBEAT:
			printf("\n");
			break;

		case SND_SEQ_EVENT_ECHO:
			{
				int i;
				
				printf("; ");
				for (i = 0; i < 8; i++) {
					printf("%02i%s", ev->data.raw8.d[i], i < 7 ? ":" : "\n");
				}
		 	}
		 	break;
			
		case SND_SEQ_EVENT_CLIENT_START:
		case SND_SEQ_EVENT_CLIENT_EXIT:
		case SND_SEQ_EVENT_CLIENT_CHANGE:
			printf("; client=%i\n", ev->data.addr.client);
			break;

		case SND_SEQ_EVENT_PORT_START:
		case SND_SEQ_EVENT_PORT_EXIT:
		case SND_SEQ_EVENT_PORT_CHANGE:
			printf("; client=%i, port = %i\n", ev->data.addr.client, ev->data.addr.port);
			break;

		default:
			printf("; not implemented\n");
	}


	switch (ev->flags & SND_SEQ_EVENT_LENGTH_MASK) {
		case SND_SEQ_EVENT_LENGTH_FIXED:
			return sizeof(snd_seq_event_t);

		case SND_SEQ_EVENT_LENGTH_VARIABLE:
			return sizeof(snd_seq_event_t) + ev->data.ext.len;
	}

	return 0;
}

void event_decoder_start_timer(snd_seq_t *handle, int queue, int client, int port)
{
	int err;
	snd_seq_event_t ev;
	
	bzero(&ev, sizeof(ev));
	ev.source.queue = queue;
	ev.source.client = client;
	ev.source.port = 0;
	ev.dest.queue = queue;
	ev.dest.client = SND_SEQ_CLIENT_SYSTEM;
	ev.dest.port = SND_SEQ_PORT_SYSTEM_TIMER;
	ev.flags = SND_SEQ_TIME_STAMP_REAL | SND_SEQ_TIME_MODE_REL;
	ev.type = SND_SEQ_EVENT_START;
	if ((err = snd_seq_event_output(handle, &ev))<0)
		fprintf(stderr, "Timer event output error: %s\n", snd_strerror(err));
	while (snd_seq_flush_output(handle)>0)
		sleep(1);
}

void event_decoder(snd_seq_t *handle, int argc, char *argv[])
{
	snd_seq_event_t *ev;
	snd_seq_port_info_t port;
	snd_seq_port_subscribe_t sub;
	fd_set in;
	int client, queue, max, err, v1, v2;
	char *ptr;

	if ((client = snd_seq_client_id(handle))<0) {
		fprintf(stderr, "Cannot determine client number: %s\n", snd_strerror(client));
		return;
	}
	printf("Client ID = %i\n", client);
	if ((queue = snd_seq_alloc_queue(handle))<0) {
		fprintf(stderr, "Cannot allocate queue: %s\n", snd_strerror(queue));
		return;
	}
	printf("Queue ID = %i\n", queue);
	if ((err = snd_seq_block_mode(handle, 0))<0)
		fprintf(stderr, "Cannot set nonblock mode: %s\n", snd_strerror(err));
	bzero(&port, sizeof(port));
	strcpy(port.name, "Input");
	if ((err = snd_seq_create_port(handle, &port)) < 0) {
		fprintf(stderr, "Cannot create input port: %s\n", snd_strerror(err));
		return;
	}
	event_decoder_start_timer(handle, queue, client, port.port);

	bzero(&sub, sizeof(sub));
	sub.sender.queue = queue;
	sub.sender.client = SND_SEQ_CLIENT_SYSTEM;
	sub.sender.port = SND_SEQ_PORT_SYSTEM_ANNOUNCE;
	sub.dest.queue = queue;
	sub.dest.client = client;
	sub.dest.port = port.port;
	sub.exclusive = 0;
	sub.realtime = 1;
	if ((err = snd_seq_subscribe_port(handle, &sub))<0) {
		fprintf(stderr, "Cannot subscribe announce port: %s\n", snd_strerror(err));
		return;
	}
	sub.sender.port = SND_SEQ_PORT_SYSTEM_TIMER;
	if ((err = snd_seq_subscribe_port(handle, &sub))<0) {
		fprintf(stderr, "Cannot subscribe timer port: %s\n", snd_strerror(err));
		return;
	}

	for (max = 0; max < argc; max++) {
		ptr = argv[max];
		if (!ptr)
			continue;
		sub.realtime = 0;
		if (tolower(*ptr) == 'r') {
			sub.realtime = 1;
			ptr++;
		}
		if (sscanf(ptr, "%i.%i", &v1, &v2) != 2) {
			fprintf(stderr, "Wrong argument '%s'...\n", argv[max]);
			return;
		}
		sub.sender.client = v1;
		sub.sender.port = v2;
		if ((err = snd_seq_subscribe_port(handle, &sub))<0) {
			fprintf(stderr, "Cannot subscribe port %i from client %i: %s\n", v2, v1, snd_strerror(err));
			return;
		}
	}
	
	while (1) {
		FD_ZERO(&in);
		FD_SET(max = snd_seq_file_descriptor(handle), &in);
		if (select(max + 1, &in, NULL, NULL, NULL) < 0)
			break;
		do {
			if ((err = snd_seq_event_input(handle, &ev))<0)
				break;
			if (!ev)
				continue;
			decode_event(ev);
			snd_seq_free_event(ev);
		} while (err > 0);
	}
}
