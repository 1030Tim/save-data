import pandas as pd
import torch
import torch.nn as nn
import torch.optim as optim


# ===================
# Load CSV
# ===================

data = pd.read_csv("dataset.csv")


x = torch.tensor(
    data[["a","b"]].values,
    dtype=torch.float32
)


y = torch.tensor(
    data[["result"]].values,
    dtype=torch.float32
)



# ===================
# Model
# ===================

class AddNet(nn.Module):

    def __init__(self):
        super().__init__()

        self.linear = nn.Linear(2,1)


    def forward(self,x):
        return self.linear(x)



model = AddNet()



# ===================
# Training
# ===================

loss_fn = nn.MSELoss()

optimizer = optim.SGD(
    model.parameters(),
    lr=0.0001
)



for epoch in range(8000):

    pred = model(x)

    loss = loss_fn(
        pred,
        y
    )


    optimizer.zero_grad()

    loss.backward()

    optimizer.step()


    if epoch % 500 == 0:
        print(
            epoch,
            loss.item()
        )



# ===================
# Test
# ===================

test = torch.tensor(
    [[50,70]],
    dtype=torch.float32
)


print(
    "prediction:",
    model(test)
)