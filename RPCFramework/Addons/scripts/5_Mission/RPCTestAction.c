class RPCTestAction extends RPCActionBase
{
    override int GetRPCType()
    {
        return RPCMANAGER_UNKNOWN_TYPE + 1;
    }   

    protected override ref Param ServerRead( ParamsReadContext ctx )
    {
        ref Param1< int > param;

        if ( ctx.Read( param ) )
        {
            return param;
        }
        return NULL;
    }

    protected override ref Param ClientRead( ParamsReadContext ctx )
    {
        ref Param1< int > param;

        if ( ctx.Read( param ) )
        {
            return param;
        }
        return NULL;
    }  

    // Verifies the action
    protected override bool VerifyAction( ref Param params, PlayerIdentity sender )
    {
        return true;
    }

    // Performs the action on the server (or in local multiplayer).
    protected override void PerformServer( ref Param params, PlayerIdentity sender )
    {
        LogError( "Testing on the server!" );
    }

    // Performs the action on the client.
    protected override void PerformClient( ref Param params, PlayerIdentity sender )
    {
        LogError( "Testing on the client!" );
    }

    void Send( int number )
    {
        if ( GetGame().IsClient() )
        {
            SendServer( new ref Param1< int >( number ) );
        } else {
            SendClient( new ref Param1< int >( number ), NULL );
        }
    }
}