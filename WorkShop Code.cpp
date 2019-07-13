rule("Author: XYLyXyRR")
{
	event
	{
		Ongoing - Global;
	}

	actions
	{
		Create HUD Text(All Players(All Teams), Hero Icon String(Hero Of(All Players(Team 2))), Players On Hero(Hero Of(All Players(
			Team 2)), Team 2), String("{0} {1}", String("{0} -> {1}", Health(All Players(Team 2)), Ultimate Charge Percent(All Players(
			Team 2)), Null), String("{0}!", Global Variable(A), Null, Null), Null), Left, -1.000, Red, Red, White, Visible To and String);
		Create HUD Text(All Players(All Teams), Hero Icon String(Hero(Mercy)), Players On Hero(Hero(Mercy), Team 1), String("{0}!", String(
			"Protect", Null, Null, Null), Null, Null), Left, 0, Blue, Blue, Blue, Visible To and String);
	}
}

rule("Rule")
{
	event
	{
		Ongoing - Global;
	}

	conditions
	{
		Is Assembling Heroes == True;
		Global Variable(D) == 0;
	}

	actions
	{
		Set Global Variable(A, 0);
		Modify Global Variable(D, Add, 1);
	}
}

rule("Mercy")
{
	event
	{
		Ongoing - Each Player;
		Team 1;
		Mercy;
	}

	actions
	{
		Create Effect(All Players(All Teams), Sparkles, Blue, Players On Hero(Hero(Mercy), All Teams), 1, Visible To Position and Radius);
	}
}

rule("Mercy by killed")
{
	event
	{
		Player earned elimination;
		Team 2;
		All;
	}

	conditions
	{
		Hero(Mercy) == Is Dead(Players On Hero(Hero(Mercy), Team 1));
	}

	actions
	{
		Modify Global Variable(A, Add, 0.500);
	}
}

rule("Invisible skill")
{
	event
	{
		Ongoing - Each Player;
		Team 2;
		All;
	}

	conditions
	{
		Is Communicating(All Players(Team 2), Ultimate Status) == True;
		Global Variable(A) >= 1;
	}

	actions
	{
		Set Slow Motion(40);
		Big Message(All Players(All Teams), String("Caution", Null, Null, Null));
		Modify Global Variable(A, Subtract, 1);
		Set Global Variable(B, Random Value In Array(All Living Players(Team 1)));
		Set Healing Received(Global Variable(B), 0);
		Set Status(Global Variable(B), Random Value In Array(All Players(Team 2)), Burning, 9999);
		Modify Global Variable(C, Add, 2);
		Wait(2, Ignore Condition);
		Kill(Global Variable(B), Event Player);
		Set Slow Motion(100);
		Set Healing Received(Global Variable(B), 100);
		Clear Status(Global Variable(B), Burning);
	}
}

rule("Invisible skill.1")
{
	event
	{
		Ongoing - Global;
	}

	conditions
	{
		Global Variable(C) >= 0;
	}

	actions
	{
		Play Effect(All Players(All Teams), Ring Explosion, Red, Global Variable(B), 5);
		Play Effect(All Players(All Teams), Bad Explosion, Red, Global Variable(B), 5);
		Play Effect(All Players(All Teams), Ring Explosion Sound, Red, Global Variable(B), 5);
		Play Effect(All Players(All Teams), Debuff Impact Sound, Red, Global Variable(B), 5);
		Play Effect(All Players(All Teams), Buff Explosion Sound, Red, Global Variable(B), 5);
		Play Effect(All Players(All Teams), Explosion Sound, Red, Global Variable(B), 5);
		Modify Global Variable(C, Subtract, 0.200);
		Wait(0.200, Ignore Condition);
		Loop If Condition Is True;
	}
}