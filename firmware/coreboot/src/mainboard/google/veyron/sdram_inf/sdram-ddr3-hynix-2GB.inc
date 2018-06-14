{
	/* 4 Hynic H5TC4G63CFR(0101b) or H5TC4G63AFR(1101b) chips */
	{
		{
			.rank = 0x1,
			.col = 0xA,
			.bk = 0x3,
			.bw = 0x2,
			.dbw = 0x1,
			.row_3_4 = 0x0,
			.cs0_row = 0xF,
			.cs1_row = 0xF
		},
		{
			.rank = 0x1,
			.col = 0xA,
			.bk = 0x3,
			.bw = 0x2,
			.dbw = 0x1,
			.row_3_4 = 0x0,
			.cs0_row = 0xF,
			.cs1_row = 0xF
		}
	},
	{
		.togcnt1u = 0x29A,
		.tinit = 0xC8,
		.trsth = 0x1F4,
		.togcnt100n = 0x42,
		.trefi = 0x4E,
		.tmrd = 0x4,
		.trfc = 0xEA,
		.trp = 0xA,
		.trtw = 0x5,
		.tal = 0x0,
		.tcl = 0xA,
		.tcwl = 0x7,
		.tras = 0x19,
		.trc = 0x24,
		.trcd = 0xA,
		.trrd = 0x7,
		.trtp = 0x5,
		.twr = 0xA,
		.twtr = 0x5,
		.texsr = 0x200,
		.txp = 0x5,
		.txpdll = 0x10,
		.tzqcs = 0x40,
		.tzqcsi = 0x0,
		.tdqs = 0x1,
		.tcksre = 0x7,
		.tcksrx = 0x7,
		.tcke = 0x4,
		.tmod = 0xC,
		.trstl = 0x43,
		.tzqcl = 0x100,
		.tmrr = 0x0,
		.tckesr = 0x5,
		.tdpd = 0x0
	},
	{
		.dtpr0 = 0x48F9AAB4,
		.dtpr1 = 0xEA0910,
		.dtpr2 = 0x1002C200,
		.mr[0] = 0xA60,
		.mr[1] = 0x40,
		.mr[2] = 0x10,
		.mr[3] = 0x0
	},
	.noc_timing = 0x30B25564,
	.noc_activate = 0x627,
	.ddrconfig = 3,
	.ddr_freq = 666*MHz,
	.dramtype = DDR3,
	.num_channels = 2,
	.stride = 9,
	.odt = 1
},