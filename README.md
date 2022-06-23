# BlockChain discussion

## Target
To provide free space to publish your thoughts without authorities <b>censorship</b>

## System content (system boundaries)
- An origin developer cannot control future development of the BlockChain
- Future development of BlockChain will be determined by community
- Each user of system has to save main idea of free discussion any theme between participants
## Communication with other platforms
- My BlockChain is fully independent of other systems and products
## Brief description
Each user will have `reputation` which depends on user `account life-time`. 

`account life-time` depends how many blocks user account exists. Every 100 blocks + 1 `reputation`

When user reaches 50 reputation - max score - he becomes `validator`.

`validator` can participate in `vote system`.

`vote system` exists to prevent from spam or another trash which will overflow block

If `vote system` against user-account reaches:
- 95% - 100% dislikes - new messages from this account will be ignored by `message queue` and user `public token` will be added to `ban list`
- 90% - 80% dislikes - new messages from this account will be ignored by `message queue` for 100 blocks and -30 `reputation`
- 80% - 70% dislikes - new messages from this account will be ignored by `message queue` for 80 blocks and -20 `reputation`
- 70% - 60% dislikes - new messages from this account will be ignored by `message queue` for 50 blocks and -10 `reputation`
- 60% - 50% dislikes - new messages from this account will be ignored by `message queue` for 20 blocks and -5 `reputation`
- 0% - 50% dislikes - user saves his reputation score

## Security of systemc
- To create new account - user has to find a unique `public key` which must start with 15 zeros
- Public key - is account `username`
- To post message at the block user has to sign it with his `private key`
- Private key - is account `password`

## Participants of the system
Every person who is willing to share his thoughts.

## Limitations of system
- When user reputation score is < 0 he automatically will be added to the `ban list` at the new block.
- one `reputation score` = one `message`
